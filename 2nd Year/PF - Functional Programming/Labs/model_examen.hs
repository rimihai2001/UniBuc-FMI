f1 :: String -> String -> String
f1 _ "" = ""
f1 "" _ = "" 
f1  (l1 : cuv1) (l2 : cuv2)
    | l1 == l2  =  l1 : f1 cuv1 cuv2
    | otherwise = ""


sumaProduse ::  [Double] -> [Double] -> Double
sumaProduse ls1 ls2 = if length ls1 /= length ls2 then error "Lungimi diferite" else sum [x^2 * y^2 | (x,y) <- zip ls1 ls2]

data PairInt = P Int Int deriving Show
data MyList = L [PairInt] deriving Show
data Exp = I Int | Add Exp Exp | Mul Exp Exp deriving Show
class MyClass m where
  toExp :: m -> Exp
  --eval1 :: Exp -> Int
  --eval :: MyList -> Int

instance MyClass MyList where
    toExp (L[])= I 1
    toExp (L ((P a b):xs)) = Mul(Add (I a)(I b)) (toExp(L xs))

eval1 :: Exp -> Int
eval1 (I x)= x
eval1 (Add exp1 exp2) = eval1 exp1 + eval1 exp2
eval1 (Mul exp1 exp2) = eval1 exp1 * eval1 exp2
    