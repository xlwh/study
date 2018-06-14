package main

import (
    "net"
    "fmt"
)

func main() {
    conn, err := net.Dial("tcp", "127.0.0.1:8080")
    defer conn.Close()
    if err != nil {
        fmt.Println("Conn server error:", err)
        return
    }

    _, err = conn.Write([]byte("hello"))
    if err != nil {
        fmt.Println("Send data error")
        return
    }

    buf := make([]byte, 1024)
    n, err := conn.Read(buf)
    if err != nil {
        fmt.Println("Read data from server error")
        return
    }
    fmt.Println("Recv data:", string(buf[:n]))
}
