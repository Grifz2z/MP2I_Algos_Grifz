let string_of_char(x:char):string=
  String.make 1 x
  
let kaboom(texte:string):char list = 
  let rec wazaboum i l=
    if i<0 then l else
      wazaboum (i-1) (texte.[i]::l) 
  in wazaboum (String.lenght texte -1) []
    
let implode l =
  let result = String.create (List.length l) in
  let rec imp i = function
  | [] -> result
  | c :: l -> result.[i] <- c; imp (i + 1) l in
  imp 0 l;;

let lzw(texte:string):int list=
  (*insert commentaires*) 
  let lt = String.length texte in 
  let dico = Hashtbl.create (256+lt*lt) (*clé:str, val: int*) in
  let 
  
    let rec lzw_aux(texte:char list)(motif:string)(code:int list)(i:int):int list=
    (*fonction auxiliaire pour lzw*)
      match texte with 
      |"" -> code (*fin texte*)
      |x::queue-> 
          let nv= motif^(string_of_char x) in (*chaine étudiée*)
          let resultat = Hashtbl.find_opt dico nv in 
          match resultat with (*disjonction selon si le motif est là ou non*)
          | None ->
              Hashtbl.add dico (i+1) nv; (*ajout motif*)  
              lzw_aux queue x code::[i+1] i+1 (*ajouter la clé au code*)         
            
          | Some x -> lzw_aux queue nv code i
    in lzw_aux texte "" [] 1

