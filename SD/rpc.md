# RPC : Remote Procedure Call

### Idée générale

- différencier le côté client et serveur
- le serveur offre la possibilité a des éléments distants d'appeler une ou plusieurs fonction à son niveau
- le client appelle localement la fonction sur un élément spécial qui relayera la demande d'appel de fonction côté serveur
- le serveur appellera la fonction et renverra le résultat côté client avec un élément spécial 
- élément spécial (talons ou stubs)

### Problème d'hétérogénéité
Pour éviter les problèmes de type entre différente machines, nous utiliserons XDR (rpc/xdr.h).

Exemples : XDR_int

### Problèmes d'identification ou nommage
Pour localiser un serveur et la procédure au sein d'un serveur, il existe plusieurs possibilités.

Trouver le serveur :
- Solution statique : écrit son adresse dans son code
- Problème : solution rigide (le serveur peut changer d'adresse)
- Solution robuste : nommage dynamique (dynamic binding)
Le serveur s'enregistre (son nom, sa version, son ip, port)








