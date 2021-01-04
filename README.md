# Season-Folder-Make

Le logiciel Season Folder Make permet de créer les dossiers des saisosn d'une série, mais peut également être adapté à d'autre type d'exigences.

## Exigences logicielles
 - Qt 5.14.0 widgets gui network
 - c++ 17

 Ces exigences, en tout cas pour la norme de c++, vas permetre des bonnes pratiques dans le futur du code.


## Présentation

Le logiciel permet de changer le nom du préfixe.

## Structure du code

Pour le moment, l'entièreté du code c++ est placé à la racine, ce qui pourras poser problème dans le futur.

Les traductions sont à placer dans le dossier **/translations/**.

### Continuité du style de programmation

Il y a 3 indications:
1. Respecter le style général du répertoire
2. Respecter le style général de la classe/namespace
3. Respecter le style général du fichier

Comme vous pouvez le voir, la majorité du code est en style Java, avec des tabulations, ce qui permet à chacun de fixer un espacement différent selon sont souhait.

Des commentaires `//TODO:` sont placés dans certains fichiers afin de faciliter la recherche de tâches.

### Note générale

Afin de faciliter la génération de documentation à l'aide d'outils comme Doxygen, merci d'essayer de commenter au mieux vos fonctions.

## Images de présentation

![Interface d'accueil](https://ik.imagekit.io/hd2xm25o42f/SFM_BASE_Hnpz8o_l_.jpg)

![3 séries d'ajoutées](https://ik.imagekit.io/hd2xm25o42f/4c4b68d7ae6353472e5c6ba42274ca68_xEgt57TnJ.png)

## Feuille de route

- [ ] Changer la langue de l'interface depuis le logiciel
- [ ] Pouvoir passer en argument le nom d'un fichier qui permet de remplir la liste des dossiers à traiter
- [ ] Argument: mode sans interuptions
- [ ] Argument: mode lancer à la suite (nécessite un fichier passé en argument)
