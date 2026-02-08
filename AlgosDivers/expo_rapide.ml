(* ************************************************************************** 
|                                                                            |
|        Alvarez Martinez Anton                                              | 
|        Algorithmes au programme de MP2I                                    |
|                                                                            |
|        Implémentation exponentiation rapide en langage Caml                |
|                                                                            |
************************************************************************** *)

let rec expo_rap (a : int)(n : int) : int =
  if n = 0 then 1
  else if n mod 2 = 0 then
    let b = expo_rap a (n/2) 
    in b*b
  else 
    let b = expo_rap a ((n-1)/2) 
    in b*b*a


let expo_rapT (a: int)(n:int) : int =
  let rec expo_aux (a: int)(n: int)(acc : int) =
    if n = 0 then acc
    else if n mod 2 = 0 then
      expo_aux (a) (n/2) (a*acc)
    else 
      expo_aux (a*a) ((n-1)/2) (acc*a)
  in expo_aux a n 1





