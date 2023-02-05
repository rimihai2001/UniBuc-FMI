bigger :: Integer -> Integer -> String
bigger a b=
    if(a>2*b)
        then "Primul parametru este mai mare decat dublul celui de-al doilea parametru"
        else "Primul parametru este mai mic sau egal decat dublul celui de-al doilea parametru"


-- main :: IO ()
-- main = do
-- let a = 5
-- let b = 2
-- print $ bigger a b