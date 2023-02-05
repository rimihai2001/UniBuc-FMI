eeny :: Integer -> String
eeny = undefined

fizzbuzz :: Integer -> String
fizzbuzz x
  | x `mod` 15 == 0 = "FizzBuzz"
  | x `mod` 3 == 0 = "Fizz"
  | x `mod` 5 == 0 = "Buzz"
  | otherwise = ""

fibonacciCazuri :: Integer -> Integer
fibonacciCazuri n
  | n < 2 = n
  | otherwise = fibonacciCazuri (n - 1) + fibonacciCazuri (n - 2)

fibonacciEcuational :: Integer -> Integer
fibonacciEcuational 0 = 0
fibonacciEcuational 1 = 1
fibonacciEcuational n =
  fibonacciEcuational (n - 1) + fibonacciEcuational (n - 2)

tribonacci :: Integer -> Integer
tribonacci = undefined

binomial :: Integer -> Integer -> Integer
binomial = undefined

verifL :: [Int] -> Bool
verifL = undefined

takefinal :: [Int] -> Int -> [Int]
takefinal = undefined

-- semiPareRec [0,2,1,7,8,56,17,18] == [0,1,4,28,9]
semiPareRec :: [Int] -> [Int]
semiPareRec [] = []
semiPareRec (h : t)
  | even h = h `div` 2 : t'
  | otherwise = t'
  where
    t' = semiPareRec t

totalLen :: [String] -> Int
totalLen [] = 0
totalLen (x : xs)
    | head x == 'A' = length x + totalLen xs
    | otherwise = totalLen xs
