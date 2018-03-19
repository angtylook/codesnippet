package main

import (
	"crypto/rand"
	"encoding/base64"
	"fmt"
)

func GenerateRandomBytes(s int) ([]byte, error) {
	b := make([]byte, s)
	n, err := rand.Read(b)
	if n != len(b) || err != nil {
		return nil, fmt.Errorf("Unable to successfully read from the system CSPRNG (%v)", err)
	}

	return b, nil
}

func GenerateRandomString(s int) (string, error) {
	b, err := GenerateRandomBytes(s)
	if err != nil {
		return "", err
	}
	return base64.URLEncoding.EncodeToString(b), nil
}

func main() {
	s, _ := GenerateRandomString(32)
	fmt.Println(s)
}
