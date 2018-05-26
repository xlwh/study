package main

import "fmt"

type Person struct {
    name string
    age int
}

func (p Person) say() {
    fmt.Println(p.name, p.age)
}

func main() {
    var p Person
    // 对对象进行赋值
    p.name = "zhanghongbin01"
    p.age = 25
    p.say()
}
