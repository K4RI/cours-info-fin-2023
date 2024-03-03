PersistLab
==========
Ces fichiers contiennent des exemples de code pour manipuler des objets persistants sans utiliser de serveur particulier

Pour exécuter ses exemples il faut

ajouter les librairies JavaDB, EclipseLink et Persistence au projet (project>Properties)

il faut démarrer le service de base de données (start Java DB dans l'onglet services)

il faut créer une nouvelle base de donnée dans JavaDB (Create Database sur JavaDB). Le nom de la bd est mydb 
mais il peut être changé. L'utilisateur et le mot de passe utilisés sont root
Si vous les changez il faudra changer le code ou le fichier persistence.xml

Exécutez en premier le programme Main et vérifiez que la table est bien créée - vous pouvez aussi vérifier que vous avez les bonnes
valeurs dans la base.

Ensuite vous devez pouvoir exécuter les exemples utilisant JDBC et JPA
