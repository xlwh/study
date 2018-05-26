package main

import "fmt"

type Person struct {
	name string
	age  int
}

func main() {
	var ps Person
	ps.name = "zhanghongbin01"
	ps.age = 25

	fmt.Println(ps.name, ps.age)
}
