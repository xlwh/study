package main

import (
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
)

func main() {
	// 先打开一个数据库连接
	db, err := sql.Open("mysql", "root:zhb01@baidu@tcp(127.0.0.1:3306)/study?charset=utf8")
	if err != nil {
		fmt.Println(err)
		return
	}

	// 插入数据
	stmt, err := db.Prepare("INSERT test SET name=?,age=?")
	if err != nil {
		fmt.Println("Prepare stmt error:", err)
		return
	}

	res, err := stmt.Exec("zhanghongbin01", 25)
	if err != nil {
		fmt.Println("exec data query error:", err)
		return
	}

	id, err := res.LastInsertId()
	if err != nil {
		fmt.Println("Query error:", err)
		return
	}
	fmt.Println("Insert data success:", id)
}
