module Main where

import System.Random.Shuffle

main :: IO () 
main = do
  ran <- shuffleM [1..100] 
  putStrLn $ show (bubble ran)

bubble :: [Int] -> [Int]
bubble l = bubbleSort l (length l) 0

bubbleSort :: [Int] -> Int -> Int -> [Int]
bubbleSort l n e
  | n == length l = bubbleSort l 0 (e-1)
  | e == 0 = l
  | otherwise = if l!!n > l!!(n+1)
        then 
          let i = l !! n
              j = l !! (n+1)
              left = take n l
              right = drop (n+1) l
          in bubbleSort (left ++ [j] ++ [i] ++ right) (n+1) e
        else bubbleSort l (n+1) e