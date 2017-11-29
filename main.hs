module Main where

import System.Random.Shuffle
import Data.List (delete, insert, transpose, insert, unfoldr)

main :: IO () 
main = do
  ran <- shuffleM [1..1000] 
  putStrLn $ show (quickSort ran)

bubble :: [Int] -> [Int]
bubble l = bubbleSort l 0 ((length l) -1)

bubbleSort :: [Int] -> Int -> Int -> [Int]
bubbleSort l n e
  | n >= (length l) -1 = bubbleSort l 0 (e-1)
  | e <= 0 = l
  | otherwise = 
    if l!!n > l!!(n+1)
    then bubbleSort ((take n l) ++ [l!!(n+1)] ++ [l!!n] ++ (drop (n+2) l)) (n+1) e
    else bubbleSort l (n+1) e

selectionSort :: (Ord a) => [a] -> [a]
selectionSort [] = []
selectionSort l = m : (selectionSort e)
                  where m = minimum l
                        e = delete m l

shellSort :: (Ord a) => [a] -> [a]
shellSort xs = foldr shellSortPhase xs gaps
  where gaps = takeWhile (< length xs) sedgewick
        sedgewick = concat [[9 * 2^n - 9 * 2^(n `div` 2) + 1, 8 * 2^(n+1) - 6 * 2^(n `div` 2) + 1] | n <- [0..]]

shellSortPhase :: (Ord a) => Int -> [a] -> [a]
shellSortPhase l = decolumnize . map insertionSort . columnize l

columnize :: Int -> [a] -> [[a]]
columnize l = transpose . takeWhile (not . null) . unfoldr (Just . splitAt l)

decolumnize :: [[a]] -> [a]
decolumnize = concat . transpose

insertionSort :: (Ord a) => [a] -> [a]
insertionSort = foldr insert []

mergeSort :: (Ord a) => [a] -> [a]
mergeSort (x:xs) = mergeSort (filter (<=x) xs) ++ [x] ++ mergeSort (filter (>x) xs)
mergeSort xs     = xs

quickSort :: (Ord a) => [a] -> [a]  
quickSort [] = []  
quickSort (x:xs) =   
    let smallerSorted = quickSort [a | a <- xs, a <= x]  
        biggerSorted = quickSort [a | a <- xs, a > x]  
    in  smallerSorted ++ [x] ++ biggerSorted  