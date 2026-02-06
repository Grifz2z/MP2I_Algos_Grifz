(* ************************************************************************** 
|                                                                            |
|        Alvarez Martinez Anton                                              | 
|        Algorithmes au programme de MP2I                                    |
|                                                                            |
|        Implémentation des piles en langage Caml                            |
|                                                                            |
|       1ère partie : Implémentation naïve par maillons chaînés              |
|       2nde partie : Pile de taille bornée – utilisation de tableaux        |
|       (à faire une fois les array vu)                                      |
|                                                                            |
************************************************************************** *)

(*Type alias pour meilleure lisibilité *)
type pile = list

let estVide (p: 'a pile) : bool = 
  (* Fonction redondante *)
  match p with
  | [] -> true
  | _ -> false

let creervide () : 'a pile = []

let empiler (p: 'a pile)(e: 'a) : 'a pile =  e::p

let rec depiler (p: 'a pile) : 'a pile =
    match p with
    | [] -> failwith "Pas de dépilage possible"
    | [a] -> a
    | _::q -> depiler q 


