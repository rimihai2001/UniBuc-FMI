import Data.Char
import Data.List
import Distribution.Simple.InstallDirs (InstallDirs(prefix))
import Text.Parsec (alphaNum)


-- 1.
rotate :: Int -> [Char] -> [Char]
rotate n l 
      | n<0 = error "Negativ"
      | n > length l = error "Mai mare decat lungimea"
      | otherwise = sufix++prefix 
            where (prefix,sufix)=splitAt n l

-- 2.
prop_rotate :: Int -> String -> Bool
prop_rotate k str = rotate (l - m) (rotate m str) == str
                        where l = length str
                              m = if l == 0 then 0 else k `mod` l

-- 3.
makeKey :: Int -> [(Char, Char)]
makeKey n = zip['A' .. 'Z'] (rotate n ['A' .. 'Z'])

-- 4.
lookUp :: Char -> [(Char, Char)] -> Char
lookUp c xs = foldr (\pc ch -> if (fst pc == c) then snd pc else ch) c xs

-- 5.
encipher :: Int -> Char -> Char
encipher n c = lookUp c (makeKey n)

-- 6.
normalize :: String -> String
normalize = map toUpper.filter isAlphaNum

-- 7.
encipherStr :: Int -> String -> String
encipherStr n = map(encipher n).normalize

-- 8.
reverseKey :: [(Char, Char)] -> [(Char, Char)]
reverseKey = map (\(x, y) -> (y, x))

-- 9.
decipher :: Int -> Char -> Char
decipher n c = lookUp c(reverseKey (makeKey n))

decipherStr :: Int -> String -> String
--decipherStr = map.decipher
decipherStr n str = filter (`elem` ['A' .. 'Z'] ++ ['0' .. '9'] ++ " ") $ map (decipher n) str
