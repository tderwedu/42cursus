# NGINX 

## FastCGI
*CGI	: Common Gateway Interface (earlier protocol)*  
Typically used to run websites that make use of PHP on the local server itself.  
FastCGI is generally used to translate client requests for an application server that does not not handle client requests directly. It is used to efficiently interface with a server that processes requests for dynamic content.

As FastCGI cannot read http headers, pertinent information is passed to the backend through parameters defined using `fastcgi_param` directive.
For the bare minimum configuration two parameters, REQUEST_METHOD and SCRIPT_FILENAME, are needed.

Nginx can use either an Unix socket or a network socket. When the FastCGI processor lives on the same host, a Unix socket is recommended for security.

### FastCGI basic configuration

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

- `QUERY_STRING`: This parameter should be set to any query string supplied by the client. This will typically be key-value pairs supplied after a “?” in the **URI**. Typically, this parameter is set to either the $query_string or $args variables, both of which should contain the same data.
    REQUEST_METHOD: This parameter indicates to the FastCGI processor which type of action was requested by the client. This is one of the few parameters required to be set in order for the pass to function correctly.
    CONTENT_TYPE: If the request method set above is “POST”, this parameter must be set. It indicates the type of content that the FastCGI processor should expect. This is almost always just set to the $content_type variable, which is set according to info in the original request.
    CONTENT_LENGTH: If the request method is “POST”, this parameter must be set. This indicates the content length. This is almost always just set to $content_length, a variable that gets its value from information in the original client request.
    SCRIPT_NAME: This parameter is used to indicate the name of the main script that will be run. This is an extremely important parameter that can be set in a variety of ways according to your needs. Often, this is set to $fastcgi_script_name, which should be the request **URI**, the request **URI** with the fastcgi_index appended if it ends with a slash, or the first captured group if using fastcgi_fix_path_info.
    SCRIPT_FILENAME: This parameter specifies the actual location on disk of the script to run. Because of its relation to the SCRIPT_NAME parameter, some guides suggest that you use $document_root$fastcgi_script_name. Another alternative that has many advantages is to use $request_filename.
    REQUEST_URI: This should contain the full, unmodified request **URI**, complete with the script to run, additional path info, and any arguments. Some applications prefer to parse this info themselves. This parameter gives them the information necessary to do that.
    PATH_INFO: If cgi.fix_pathinfo is set to “1” in the PHP configuration file, this will contain any additional path information added after the script name. This is often used to define a file argument that the script should act upon. Setting cgi.fix_pathinfo to “1” can have security implications if the script requests are not sanitized through other means (we will discuss this later). Sometimes this is set to the $fastcgi_path_info variable, which contains the second captured group from the fastcgi_split_path_info directive. Other times, a temporary variable will need to be used as that value is sometimes clobbered by other processing.
    PATH_TRANSLATED: This parameter maps the path information contained within PATH_INFO into an actual filesystem path. Usually, this will be set to something like $document_root$fastcgi_path_info, but sometimes the later variable must be replaced by the temporary saved variable as indicated above.

### proxy_pass
Running in actual (reverse) proxy mode, forwarding incoming request to another server

