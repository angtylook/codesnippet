package main

import (
	"fmt"
	"net"
	"os"
)

func main() {
	addr := "www.baidu.com"
	ip, err := net.ResolveIPAddr("ip", addr)
	if err != nil {
		fmt.Println("Resolvation error:#", err.Error())
		os.Exit(1)
	}
	fmt.Println("Resolved address is:", ip.String())
}
