package main

import "fmt"

type Person struct {
    var name string
    var age int
}

func main() {
    p := new(Person)
    *p.name = "zhanghongbin01"
    *p.age = 25

    fmt.Println(*p.name, *p.age)
}
