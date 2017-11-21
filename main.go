package main

import (
  "fmt"
  "math/rand"
)

func bubble(list []int) []int {
  swaped := true
  for swaped {
    swaped = false
    for i := 0; i < len(list) -1; i++ {
      if list[i] > list[i + 1] {
        list[i], list[i+1] = list[i+1], list[i]
        swaped = true
      }
    }
  }
  return list
}

func main() {
  var list []int
  for i := 0; i < 1000; i++ {list = append(list, rand.Intn(100))}
  sorted := bubble(list)
  fmt.Println(sorted)
}