(* ************************************************************************** 
|                                                                            |
|        Alvarez Martinez Anton                                              | 
|        Algorithmes au programme de MP2I                                    |
|                                                                            |
|        Implémentation des files en langage Caml                            |
|                                                                            |
|       1ère partie : Implémentation naïve par maillons chaînés              |
|       2nde partie : Pile de taille bornée – utilisation de tableaux        |
|       (à faire une fois les array vu)                                      |
|                                                                            |
************************************************************************** *)

(*Type alias pour meilleure lisibilité *)
type file = list

let est_vide (f : 'a file) : bool =
  f = []


let creer_vide () : 'a file = []

let enfiler (f : 'a file) (e : 'a) : 'a file =
  f @ [e]


let defiler (f : 'a file) : 'a file =
  match f with
  | [] -> failwith "File vide"
  | _::q -> q
