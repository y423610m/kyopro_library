/*
論理演算関係メモ
A|B
    1-~a&~b bitドモルガン ABC291G
    a^b + a&b == (a^b) | (a&b) 

A&B
    1-~a|~b bitドモルガン
    a|b - a^b 

A^B
    a|b - a&b
    a^a = 0
    可換

A+B
    a^b + (a&b)<<1
    a|b - a&b + (a&b)<<1

A-B

A*B

A/B

A%B



*/