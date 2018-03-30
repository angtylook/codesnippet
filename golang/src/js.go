package main

import (
	"encoding/json"
	"fmt"
	"strconv"
)

type NegateIsEmpty int

func (n NegateIsEmpty) MarshalJSON() ([]byte, error) {
	v := int64(n)
	if v >= 0 {
		return []byte(strconv.FormatInt(v, 10)), nil
	}
	return []byte("null"), nil
}

type Message struct {
	Name string
	Body string
	Time int64
	F    NegateIsEmpty `json:",omitempty"`
}

func main() {
	m := Message{"Alice", "Hello", 1234, -1}
	b, err := json.Marshal(m)
	if err == nil {
		fmt.Println(string(b))
	} else {
		fmt.Println(err)
	}
}
