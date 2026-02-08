(* ************************************************************************** 
|                                                                            |
|        Alvarez Martinez Anton                                              | 
|        Algorithmes au programme de MP2I                                    |
|                                                                            |
|        Implémentation du tri par insetion en langage Caml                  |
|                                                                            |
|       1ère partie : Implémentation récursive non terminale                 |
|       2nde partie : Implémentation récursive terminale                     |
|                                                                            |
************************************************************************** *)

(* 1 - non terminale*)

let rec insere (l : 'a list)(e : 'a) : 'a list =
  (*Retour : une liste avec l et l'elemnt e inseré au bon endroit par odre croissant
   Non récursive terminale.*)
  match l with 
  | [] -> [e]
  | t::q -> 
      if t>e then e::l
      else t::insere q e

let rec tri_insertion (l: 'a list) : 'a list =
  (*Retour : une nouvelle liste contenant les mêmes éléments que l,
   mais triés par ordre croissant *)
  match l with 
  | [] -> []
  | t::q -> insere (tri_insertion q) t 
  (*On insère ensuite l'élément t dans cette liste déjà triée*)

(* 2 - terminale*)

let rec tri_insertion (l: 'a list) : 'a list = 
  let rec insere (l : 'a list)(e : 'a)(acc : 'a list) : 'a list =
  (*Retour : une liste avec l et l'elemnt e inseré au bon endroit par odre croissant
   Non récursive terminale.*)
    match l with 
    | [] -> acc
    | t::q -> 
        if t>e then insere l e (e::acc)
        else insere l e (t::acc)
  in let rec trie l acc =
  (*Retour : une nouvelle liste contenant les mêmes éléments que l,
   mais triés par ordre croissant *)
    match l with
    | [] -> acc
    | t::q -> trie q (insere acc t [])
  in
  aux l []
