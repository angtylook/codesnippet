package main

import (
	"fmt"
	"io/ioutil"
	//"os"
	"crypto/md5"
	"crypto/rand"
	"encoding/hex"
	"encoding/xml"
	"flag"
	"net/http"
	"net/url"
	//"errors"
)

func GetMid() string {
	buf := make([]byte, 16)
	n, err := rand.Read(buf)
	if n != 16 || err != nil {
		fmt.Println("GetMid rand errors.")
		return "0e57829dbda784cc39ba72d2f05d5b96"
	}
	mid := hex.EncodeToString(buf)
	return mid[:32]
}

func GetServerSign(key, version string) string {
	sgin_str := key + version + "sdf23qa2344e&&^sdw&2ds446"
	md5_hash := md5.New()
	md5_hash.Write([]byte(sgin_str))
	sgin := hex.EncodeToString(md5_hash.Sum([]byte(nil)))
	return sgin
}

func GetRequestUrl(mid, uid, from, version, oemid string) string {
	request_url := "http://policy.game.yy.com/client/query.do?"
	key := mid
	if oemid == "0" {
		key = uid
	}

	param := url.Values{}
	param.Add("mid", mid)
	param.Add("uid", uid)
	param.Add("ver", version)
	param.Add("oemid", oemid)
	param.Add("from", from)
	param.Add("auto", GetServerSign(key, version))

	request_url = request_url + param.Encode()
	return request_url
}

func RequestForUpdate(url string) ([]byte, error) {
	response, err := http.Get(url)
	if err != nil {
		return nil, fmt.Errorf("%v", err)
	}

	defer response.Body.Close()
	//io.Copy(os.Stdout, response.Body)
	buf, err := ioutil.ReadAll(response.Body)
	if err != nil {
		fmt.Println(err)
	}
	//fmt.Println("read bytes: ", len(buf))
	return buf, nil
}

func GetCmd() (mid, uid, from, version, oemid string) {
	flag.StringVar(&mid, "mid", GetMid(), "machine id")
	flag.StringVar(&uid, "uid", "", "yyuid, can be empty")
	flag.StringVar(&from, "from", "", "who run me")
	flag.StringVar(&version, "ver", "0.1.39.0", "the current version")
	flag.StringVar(&oemid, "oemid", "10", "can be 0, 10, 19")
	flag.Parse()

	fmt.Println("mid = ", mid)
	fmt.Println("uid = ", uid)
	fmt.Println("from = ", from)
	fmt.Println("version = ", version)
	fmt.Println("oemid = ", oemid)
	//"0e57829dbda784cc39ba72d2f05d5b96",
	if len(mid) != 32 {
		mid = "0e57829dbda784cc39ba72d2f05d5b96"
	}

	if oemid == "0" && uid == "" {
		uid = "50004303"
	}

	return mid, uid, from, version, oemid
}

type Option struct {
	Name  string `xml:"name,attr"`
	Value string `xml:"value,attr"`
}

type Result struct {
	Statecode string `xml:"Statecode,attr"`
	Url       string `xml:"url,attr"`
	Version   string `xml:"versionNo,attr"`
}

type UpdateInformation struct {
	XMLName     xml.Name `xml:"update"`
	Information Result   `xml:"result"`
	Options     []Option `xml:"options>option"`
}

type OldResult struct {
	XMLName   xml.Name `xml:"result"`
	Statecode string   `xml:"Statecode,attr"`
	Url       string   `xml:"url,attr"`
	Version   string   `xml:"versionNo,attr"`
	ShowTips  string   `xml:"showTip,attr"`
	Restart   string   `xml:"tipRestart,attr"`
}

func main() {
	url := GetRequestUrl(GetCmd())
	//fmt.Println(url)
	buf, err := RequestForUpdate(url)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println("buffer = ", string(buf))

	oemid := flag.Lookup("oemid")
	if oemid.Value.String() == "10" {
		var result UpdateInformation
		err = xml.Unmarshal(buf, &result)
		if err != nil {
			fmt.Println(err)
		}

		fmt.Println("Update Information: ")
		fmt.Println("status code = ", result.Information.Statecode)
		fmt.Println("url = ", result.Information.Url)
		fmt.Println("new version = ", result.Information.Version)

		fmt.Println("Options: ")
		for _, option := range result.Options {
			fmt.Println(option.Name, " = ", option.Value)
		}
	} else {
		var result OldResult
		err = xml.Unmarshal(buf, &result)
		if err != nil {
			fmt.Println(err)
		}
		fmt.Println("Update Information")
		fmt.Println("status code = ", result.Statecode)
		fmt.Println("url = ", result.Url)
		fmt.Println("new version = ", result.Version)
		fmt.Println("Options: ")
		fmt.Println("showTip = ", result.ShowTips)
		fmt.Println("tipRestart = ", result.Restart)
	}

	return
}
