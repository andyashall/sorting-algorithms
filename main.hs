module Main where

import System.Random.Shuffle
import Data.List (delete, insert)

main :: IO () 
main = do
  ran <- shuffleM [1..100] 
  putStrLn $ show (insertionSort ran)

bubble :: [Int] -> [Int]
bubble l = bubbleSort l 0 ((length l) -1)

bubbleSort :: [Int] -> Int -> Int -> [Int]
bubbleSort l n e
  | n >= (length l) -1 = bubbleSort l 0 (e-1)
  | e <= 0 = l
  | otherwise = 
    if l!!n > l!!(n+1)
    then 
      let i = l !! n
          j = l !! (n+1)
          left = take n l
          right = drop (n+2) l
      in bubbleSort (left ++ [j] ++ [i] ++ right) (n+1) e
    else bubbleSort l (n+1) e

selectionSort :: (Ord a) => [a] -> [a]
selectionSort [] = []
selectionSort l = m:(selectionSort e)
                  where m = minimum l
                        e = delete m l

insertionSort :: Ord a => [a] -> [a]
insertionSort = foldr insert []