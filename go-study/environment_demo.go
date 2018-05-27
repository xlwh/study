package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	os.Setenv("name", "zhanghongbin01")
	os.Setenv("age", "25")

	for _, e := range os.Environ() {
		pair := strings.Split(e, "=")
		fmt.Println(pair[0], pair[1])
	}
}
