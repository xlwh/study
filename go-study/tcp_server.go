package main

import (
	"bytes"
	"fmt"
	"io"
	"net"
)

func main() {
	var listener net.Listener
	listener, err := net.Listen("tcp", "127.0.0.1:8080")
	defer listener.Close()
	if err != nil {
		fmt.Println("Listen the server port error")
		return
	}

	// 阻塞等待客户端连接过来
	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Accept the client connection error")
			return
		}
		// 在另外的线程中处理请求
		fmt.Println("Get a client")
		go handle(conn)
	}
}

func handle(conn net.Conn) {
	// 记得释放连接
	defer func() {
		fmt.Println("Close a connection")
		conn.Close()
	}()

	var result bytes.Buffer
	for {
		buf := make([]byte, 5)
		n, err := conn.Read(buf)
		fmt.Println("xxxxx")
		if err != nil {
			if err == io.EOF {
				break
			}
			fmt.Println("Read data error")
			return
		}
		if n > 0 {
			result.Write(buf[:n])
		}
	}

	// 输出结果
	fmt.Println(result.String())

	// 给客户端返回数据
	conn.Write([]byte("Process done"))
}
