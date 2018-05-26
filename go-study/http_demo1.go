package main

import (
	"fmt"
	"log"
	"net/http"
	"strings"
)

// 设置http处理的回调函数
func handler(resp http.ResponseWriter, r *http.Request) {
	r.ParseForm() // 需要主动解析http协议的请求参数，默认是不会解析的
	fmt.Println(r.Form)
	fmt.Println("path", r.URL.Path)

	for k, v := range r.Form {
		fmt.Println("key:", k)
		fmt.Println("val:", strings.Join(v, ""))
	}

	// 给客户端返回数据
	fmt.Fprintf(resp, "Hello astaxie")
}

func main() {
	http.HandleFunc("/", handler)
	err := http.ListenAndServe(":9090", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
