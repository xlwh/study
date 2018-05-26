package main

import (
	"encoding/json"
	"fmt"
)

func main() {
	b := []byte(`{"Name":"zhanghongbin001", "Age":6, "Parents":["zhangsan", "lisi"]}`)
	var f interface{}
	err := json.Unmarshal(b, &f)

	if err != nil {
		fmt.Println("Parse json error")
		return
	}

	// 把数据转成map来进行访问
	m := f.(map[string]interface{})

	for k, v := range m {
		switch vv := v.(type) {
		case string:
			fmt.Println(k, "is string", vv)
		case int:
			fmt.Println(k, "is int", vv)
		case []interface{}:
			fmt.Println(k, "is array:")
			for i, u := range vv {
				fmt.Println(i, u)
			}
		}
	}

}
