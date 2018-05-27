package main

import (
	"flag"
	"fmt"
)

func main() {
	name := flag.String("name", "zhanghongbin01", "your name")
	age := flag.Int("age", 25, "Your age")

	flag.Parse()
	fmt.Println(*name, *age)
}
