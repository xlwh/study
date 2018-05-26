package main

import (
	"encoding/base64"
	"fmt"
)

func main() {
	var str string = "abcadadadadadad"

	// 进行base64编码
	strEncode := base64.StdEncoding.EncodeToString([]byte(str))
	fmt.Println("encoded:", strEncode)

	// 进行解码
	sDesc, err := base64.StdEncoding.DecodeString(strEncode)
	if err != nil {
		fmt.Println("Decode base64 error:", err)
		return
	}

	fmt.Println("Decode success, the result is:", string(sDesc))
}
