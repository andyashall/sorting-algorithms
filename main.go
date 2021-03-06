package main

import (
  "fmt"
  "math/rand"
  // "sort"
)

func bubble(list []int) []int {
  for n := len(list) -1; n >= 0; n-- {
    for i := 0; i < len(list) -1; i++ {
      if list[i] > list[i + 1] {
        list[i], list[i+1] = list[i+1], list[i]
      }
    }
  }
  return list
}

func selection(list []int) []int {
  for n := len(list) - 1; n >= 0; n-- {
    larg := 0
    for i := 0; i < n; i++ {
      if list[i] > list[larg] {
        larg = i
      }
    }
    list[n], list[larg] = list[larg], list[n]
  }
  return list
}

func insertion(list []int) []int {
  for n := 1; n < len(list); n++ {
    c := list[n]
    p := n
    for p > 0 && list[p-1] > c {
      list[p] = list[p-1]
      p--
    }
    list[p] = c
  }
  return list
}

func shell(list []int) []int {
  split := int(len(list) / 2)
  for split > 0 {
    for i := 0; i < len(list); i++ {
      gapInsertion(list, i, split)
    }
    split = int(split / 2)
  }
  return list
}

func gapInsertion(l []int, s int, e int) []int {
  for n := s+e; n < len(l); n+=e {
    c := l[n]
    p := n
    for p >= e && l[p-e] > c {
      l[p] = l[p-e]
      p = p-e
    }
    l[p] = c
  }
  return l
}

func merge(list []int) []int {
  if len(list) > 1 {
    split := int(len(list) / 2)
    left := list[:split]
    right := list[split:]
    merge(left)
    merge(right)
    i, j, k := 0, 0, 0
    for i < len(left) && j < len(right) {
      if left[i] < right[j] {
        list[k] = left[i]
        i++
      } else {
        list[k] = right[j]
        j++
      }
    }
    for i < len(left) {
      list[k] = left[i]
      i++
      k++
    }
    for j < len(right) {
      list[k] = right[j]
      j++
      k++
    }
    return list
  }
  return list
}

func quick(list []int) []int {
  return qs(list, 0, len(list)-1)
}

func qs(list []int, left int, right int) []int {
  if left <= right {
    part := partition(list, left, right)
    qs(list, left, part - 1)
    qs(list, part + 1, right)
  }
  return list
}

func partition(list []int, left int, right int) int {
  l := left+1
  r := right
  done := false
  for done == false {
    for l <= r && list[l] <= list[left] {
      l++
    }
    for list[r] >= list[left] && r >= l {
      r--
    }
    if r <= l {
      done = true
    } else {
      list[l], list[r] = list[r], list[l]
    }
  }
  list[left], list[r] = list[r], list[left]
  return r
}

func mean(list []int) int {
  var o int
  for i := 0; i < len(list); i++ {
    o = o + list[i] 
  }
  return o / len(list)
}

func main() {
  var list []int
  for i := 0; i < 10000; i++ {list = append(list, rand.Intn(10000))}
  sorted := quick(list)
  fmt.Println(sorted)
}