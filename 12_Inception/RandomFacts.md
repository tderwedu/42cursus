# NGINX 

## `FastCGI`
*CGI	: Common Gateway Interface (earlier protocol)*  
Typically used to run websites that make use of PHP on the local server itself.  
FastCGI is generally used to translate client requests for an application server that does not not handle client requests directly. It is used to efficiently interface with a server that processes requests for dynamic content.

As FastCGI cannot read http headers, pertinent information is passed to the backend through parameters defined using `fastcgi_param` directive. Nginx converts the headers in an `HTTP` request into environment variables prefixed with `HTTP_`. An application can then look up the value of request headers by inspecting its environment.

Nginx can use either an Unix socket or a network socket. When the FastCGI processor lives on the same host, a Unix socket is recommended for security.

### FastCGI basic configuration

For the bare minimum configuration two parameters, REQUEST_METHOD and SCRIPT_FILENAME, are needed.

- `fastcgi_param REQUEST_METHOD $request_method` : the http method requested by the client.
- `fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name` :
	- **$document_root** :  path to the base directory, as set by the `root` directive
	- **$fastcgi_script_name** :  set to the request **URI**
- `fastcgi_index index.php` : if the request **URI** ends with a slash `/`, this value is appended.
- `fastcgi_pass unix:/run/php/php7.3-fpm.sock` : 

### Common FastCGI Directives
- `fastcgi_pass` : This defines the location where the FastCGI processor can be reached.
- `fastcgi_param` : The array directive that can be used to set FastCGI parameters to values.
- `try_files` : *Not a FastCGI-specific directive.* This is often used as part of a request sanitation routine to make sure that the requested file exists before passing it to the FastCGI processor.
- `include` : *Not a FastCGI-specific directive.* Used to include common, shared configuration details in multiple locations.
- `fastcgi_split_path_info` : defines a regular expression with two captured groups. The first is the `$fastcgi_script_name` variable. The second is the `$fastcgi_path_info` variable. Both of these are used to distinguish the files to run from the additional information.
- `fastcgi_index` : : if the request **URI** ends with a slash `/`, this value is appended.
- `fastcgi_intercept_errors`: defines whether errors received from the FastCGI server should be handled by Nginx or passed directly to the client.

### Nginx Variables Used with FastCGI
- `$query_string` or `$args` : The arguments given in the original client request.
- `$is_args`: Will equal “?” if there are arguments in the request and will be set to an empty string otherwise.
- `$request_method` : indicates the original client request method.
- `$content_type` : the Content-Type request header. This information is needed by the proxy if the user’s request is a POST in order to correctly handle the content that follows.
- `$content_length`:  value of the Content-Length header from the client. This information is required for any client POST requests.
- `$fastcgi_script_name` : contains the script file to be run. If the request ends in a slash (`/`), the value of the `fastcgi_index` directive will be appended to the end. In the event that the `fastcgi_split_path_info` directive is used, this variable will be set to the first captured group defined by that directive. The value of this variable should indicate the actual script to be run.
- `$request_filename`: contains the file path for the requested file. It gets this value by taking the value of the current document root, taking into account both the root and alias directives, and the value of `$fastcgi_script_name`. This is a very flexible way of assigning the `SCRIPT_FILENAME` parameter.
- `$fastcgi_path_info` : contains additional path info that may be available after the script name in the request. This value sometimes contains another location that the script to execute should know about. This variable gets its value from the second captured regex group when using the `fastcgi_split_path_info` directive.
- `$document_root` : contains the current document root value. This will be set according to the root or alias directives.
- `$uri` : This variable contains the current **URI** with normalization applied. This variable is modified by directives that rewrite or apply internal redirection on the **URI**.
- `$request_uri` : The entire request as received from the client. This includes the script, any additional path info, plus any query strings.

### Common FastCGI Parameters

- `QUERY_STRING`: This parameter should be set to any query string supplied by the client. This will typically be key-value pairs supplied after a “?” in the **URI**. Typically, this parameter is set to either the `$query_string` or `$args` variables, both of which should contain the same data.
- `REQUEST_METHOD` : This parameter indicates to the FastCGI processor which type of action was requested by the client. This is one of the few parameters required to be set in order for the pass to function correctly.
- `CONTENT_TYPE` : If the request method set above is *POST*, this parameter must be set. It indicates the type of content that the FastCGI processor should expect. This is almost always just set to the `$content_type` variable, which is set according to info in the original request.
- `CONTENT_LENGTH` : If the request method is *POST*, this parameter must be set. This indicates the content length. This is almost always just set to *$content_length*, a variable that gets its value from information in the original client request.
- `SCRIPT_NAME` : This parameter is used to indicate the name of the main script that will be run. This is an extremely important parameter that can be set in a variety of ways according to your needs. Often, this is set to `$fastcgi_script_name`, which should be the request **URI**, the request **URI** with the `fastcgi_index` appended if it ends with a slash, or the first captured group if using `fastcgi_fix_path_info`.
- `SCRIPT_FILENAME` : This parameter specifies the actual location on disk of the script to run. Because of its relation to the `SCRIPT_NAME` parameter, some guides suggest that you use `$document_root` `$fastcgi_script_name`. Another alternative that has many advantages is to use `$request_filename`.
- `REQUEST_URI` : This should contain the full, unmodified request **URI**, complete with the script to run, additional path info, and any arguments. Some applications prefer to parse this info themselves. This parameter gives them the information necessary to do that.
- `PATH_INFO` : If `cgi.fix_pathinfo` is set to `1` in the PHP configuration file, this will contain any additional path information added after the script name. This is often used to define a file argument that the script should act upon. Setting `cgi.fix_pathinfo` to `1` can have security implications if the script requests are not sanitized through other means. Sometimes this is set to the `$fastcgi_path_info variable`, which contains the second captured group from the `fastcgi_split_path_info directive`. Other times, a temporary variable will need to be used as that value is sometimes clobbered by other processing.
- `PATH_TRANSLATED` : This parameter maps the path information contained within `PATH_INFO` into an actual filesystem path. Usually, this will be set to something like `$document_root` `$fastcgi_path_info`, but sometimes the later variable must be replaced by the temporary saved variable as indicated above.

### proxy_pass
Running in actual (reverse) proxy mode, forwarding incoming request to another server

# PHP FPM (FastCGI Process Manager)
This guide assume PHP FPM already installed and configured either using tcp port (127.0.0.1:9000) or unix socket (/var/run/php-fpm.sock).

Ah - that makes more sense. So we need to resolve etc/php-fpm.d/*.conf relative to /usr/local. Resulting in /usr/local/etc/php-fpm.d/*.conf (usually you'll at least find a www.conf file in there). The pool config determines amongst other things how php-fpm listens for connections (e.g. via Unix socket or via TCP IP:port).

Note the `fastcgi_pass docker-php-fpm:9000;` line that tells nginx how to reach our php-fpm service.

Maintenant, si vous voulez configurer PHP, il faudra éditer la configuration dans le répertoire  /etc/php/7.2/fpm  . Voici le détail du contenu de ce répertoire :
 - `php.ini` le fichier de configuration générale de PHP
 - `conf.d` le répertoire de configuration des modules PHP
 - `php-fpm.conf` le fichier de configuration du daemon php-fpm
 - `pool.d` le répertoire contenant la configuration des pools php-fpm

Php-fpm fonctionne par un système de pools, un pool étant un ensemble de processus php-fpm utilisant une même configuration.


# MySQL - MariaDB

```
mysql -h localhost -u root -p
```
 - `mysql` le nom du client texte qui permet de se connecter à MySQL
 - `-h` précise le nom de l’hôte auquel vous voulez vous connecter. localhost est l’hôte par défaut donc vous pouvez vous passer de cette option pour les connexions locales
- `-u` indique le nom de l’utilisateur avec lequel vous voulez vous connecter
- `-p` demande d’afficher un prompt pour entrer le mot de passe de manière interactive

Dans MySQL, la manière dont les données sont gérées et accédées est définie au niveau de chaque table. Cette gestion est assurée par des moteurs de stockage, chacun ayant ses caractéristiques propres. Les deux types de moteurs principaux que vous devez connaître avec MySQL sont :

    MyISAM : c’est le moteur le plus ancien et le plus “basique”. Il est très rapide pour effectuer des recherches ou des opérations en lecture mais ne gère pas les transactions (cf encadré) ni les clés étrangères.

    InnoDB : c’est un moteur plus récent. Il est plus robuste dans le sens où il gère les transactions mais il est un peu plus lent pour les opérations de lecture. Il gère aussi les clés étrangères.

Une transaction est une opération dite ACID pour atomique, cohérente, isolée et durable. En gros, ça veut dire qu’une opération est soit réalisée, soit non-réalisée mais n’est jamais quelque part entre les deux. C’est un critère important pour certaines opérations comme les opérations bancaires par exemple : si un transfert d’argent est réalisé, le compte de l’émetteur est prélevé ET l’argent est versé au bénéficiaire mais jamais l’un sans l’autre.

Les fichiers de configuration utilisés par MySQL sont dans `/etc/mysql` . Vous y découvrirez :

    les fichiers `my.cnf` et  mysql.cnf  : fichiers généraux par défaut, ils ne contiennent maintenant que des lignes pour inclure les fichiers dans  conf.d  et  mysql.conf.d  car la configuration a été découpée en différents fichiers dans ces répertoires

    un fichier `debian.cnf` : sur les systèmes Debian (dont Ubuntu), un utilisateur  debian-sys-maint  ayant les droits administrateur est créé pour effectuer les opérations de maintenance de MySQL. Ce fichier contient les informations de connexion de cet utilisateur et ne doit pas être modifié.

    un fichier `mysql.conf.d/mysqld.cnf` : il contient la plupart des options de configuration générale du serveur.

Si vous ouvrez ce dernier fichier  /etc/mysql/mysql.conf.d/mysqld.cnf  , vous verrez que les fichiers de configuration de MySQL sont découpés en sections dont le titre est entre crochets. La configuration générale est dans la section  [mysqld]  . Vous y trouverez quelques variables notables :
 - `user = mysql` Définit l’utilisateur système utilisé par MySQL.
 - `port = 3306` Définit le port TCP sur lequel écoute MySQL
 - `datadir = /var/lib/mysql` Définit le répertoire dans lequel MySQL stocke ses fichiers
 - `bind-address = 127.0.0.1` Définit les IP sur lesquelles écoute MySQL. Sur Ubuntu, par défaut MySQL n’écoute qu’en local ce qui est une bonne chose en terme de sécurité. Comme votre serveur est sur la même machine que MySQL, vous pouvez laisser comme ça pour l’instant mais c’est à adapter si vous voulez vous connecter à MySQL depuis un autre serveur.
 - `log_error = /var/log/mysql/error.log` Définit le log d’erreurs de MySQL

 Dans le répertoire de stockage `/var/lib/mysql`, vous y trouverez un sous-répertoire pour chacune de vos bases de données. Dans ces répertoires de base de données, vous trouverez pour chaque table un fichier NOM_DE_MA_TABLE.frm  qui décrit la structure de la table en question. Les autres fichiers dépendent du moteur de stockage que vous utilisez pour vos tables.

mysqld_safe is the recommended way to start a mysqld server on Unix and NetWare. mysqld_safe adds some safety features such as restarting the server when an error occurs and logging runtime information to an error log file. NetWare-specific behaviors are listed later in this section.
