package main

import (
  "fmt"
  "math/rand"
)

func main() {
  var list []int
  for i := 0; i < 1000; i++ {list = append(list, rand.Intn(100))}
  fmt.Println(list)
}