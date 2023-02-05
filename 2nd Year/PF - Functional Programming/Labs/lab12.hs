{-
class Functor f where
fmap : : ( a -> b ) -> f a -> f b
-}
instance Functor Identity where  
    fmap f (Identity x) = Identity (f x)  
    
newtype Identity a = Identity a


instance Functor Pair where  
    fmap f (Pair x y) = Pair (f x) (f y)

data Pair a = Pair a a

instance Functor (Constant a) where  
    fmap f (Constant b) = Constant (f b)

data Constant a b = Constant b

instance Functor (Two a) where  
    fmap f (Two a b) = Two a (f b)

data Two a b = Two a b

instance Functor (Three a b) where  
    fmap f (Three a b c) = Three a b (f c)

data Three a b c = Three a b c

instance Functor (Three' a) where  
    fmap f (Three' a b1 b2) = Three' a (f b1) (f b2)

data Three' a b = Three' a b b

instance Functor (Four a b c) where  
    fmap f (Four a b c d) = Four a b c (f d)
data Four a b c d = Four a b c d

instance Functor (Four'' a) where  
    fmap f (Four'' a1 a2 a3 b1) = Four'' a1 a2 a3 (f b1)
data Four'' a b = Four'' a a a b

instance Functor (Quant x) where
    fmap f Finance = Finance
    fmap f(Desk x) = Desk x
    fmap f (Bloor x) = Bloor (f x)
data Quant a b = Finance | Desk a | Bloor b



instance Functor f => Functor (LiftItOut f) where
    fmap f(LiftItOut f_a) = LiftItOut (fmap f f_a)
data LiftItOut f a = LiftItOut (f a)

instance (Functor f, Functor g) => Functor (Parappa f g) where
    fmap f(DaWrappa f_a g_a) = DaWrappa (fmap f f_a) (fmap f g_a)

data Parappa f g a = DaWrappa (f a) (g a)

instance (Functor f, Functor g) => Functor (IgnoreOne f g a) where
    fmap f (IgnoringSomething f_a g_b) = IgnoringSomething f_a (fmap f g_b)

data IgnoreOne f g a b = IgnoringSomething (f a) (g b)

instance Functor g => Functor (Notorious g o a) where
    fmap f(Notorious g_o g_a g_t) = Notorious g_o g_a (fmap f g_t)
data Notorious g o a t = Notorious (g o) (g a) (g t)

instance Functor GoatLord where
    fmap f = mapGoat
        where
            mapGoat NoGoat = NoGoat
            mapGoat (OneGoat a) = OneGoat (f a)
            mapGoat (MoreGoats a1 a2 a3) = MoreGoats (mapGoat a1) (mapGoat a2) (mapGoat a3)
data GoatLord a = NoGoat | OneGoat a | MoreGoats (GoatLord a) (GoatLord a) (GoatLord a)

instance Functor TalkToMe where
    fmap = funcTalk
        where
            funcTalk f Halt = Halt
            funcTalk f (Print s1 a1) = Print s1 (f a1)
            funcTalk f (Read g) = Read (f.g) 

data TalkToMe a = Halt | Print String a | Read (String -> a)
