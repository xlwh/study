package main

import (
	"fmt"
	"log"
	"os"
	"time"
)

func main() {
	reader, writer, err := os.Pipe()
	if err != nil {
		log.Fatalln("Error to create pipe")
		panic(err)
	}

	// 在匿名的协程中读数据
	go func() {
		out := make([]byte, 100)
		n, err := reader.Read(out)
		if err != nil {
			log.Fatalln("Error to read data")
			panic(err)
		}
		fmt.Println(string(out[:n]))
	}()

	// 写入数据
	_, err = writer.Write([]byte("hello"))
	if err != nil {
		log.Fatalln("Error to write data")
		panic(err)
	}

	// 睡眠一会
	time.Sleep(200 * time.Millisecond)
}
