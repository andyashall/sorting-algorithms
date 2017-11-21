module Main where

import System.Random.Shuffle

main :: IO () 
main = do
  ran <- shuffleM [1..100] 
  putStrLn $ show (length ran)