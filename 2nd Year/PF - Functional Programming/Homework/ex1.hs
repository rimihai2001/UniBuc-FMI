paritate :: Integer -> String
paritate n=
    if(n `mod` 2 == 0)
        then "Par"
        else "Impar"


-- main :: IO ()
-- main = do
-- let n = 5
-- print $ paritate n