package main

import (
	"fmt"
	"io/fs"

	"embed"
)

//go:embed hello
var cfgFS embed.FS

func main() {
	fs.WalkDir(cfgFS, ".", func(path string, d fs.DirEntry, err error) error {
		fmt.Println(path)
		if err != nil {
			fmt.Println(err.Error())
			return nil
		}
		if d.IsDir() {
			// fmt.Println("is dir")
			return nil
		}
		if !d.Type().IsRegular() {
			fmt.Println("unknown type")
			return nil
		}
		// fmt.Println("is regular")
		// content, _ := cfgFS.ReadFile(path)
		// fmt.Println(string(content))
		return nil
	})
}
