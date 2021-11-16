<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('MYSQL_DATABASE') );

/** MySQL database username */
define( 'DB_USER', getenv('MYSQL_USER') );

/** MySQL database password */
define( 'DB_PASSWORD', getenv('MYSQL_PASSWORD') );

/** MySQL hostname */
// define( 'DB_HOST', getenv_docker('MYSQL_HOST', 'bad_host') );
define( 'DB_HOST', getenv('MYSQL_HOST') );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

define('AUTH_KEY',         'z67>MY{g> mp^D#|~$d; ^x >r9U$MJFwK0g:/;uW!BSaC<V~9V*BzWi1h&FbfZW');
define('SECURE_AUTH_KEY',  'p$wJWcPLCFjJ?+%yoYOn,K.${In|$L-O[<Nm5Il;1-K!%`/K$<:(]YUE1`lt.H{m');
define('LOGGED_IN_KEY',    '-*?Tu7W+GWn>q6=oO.-:(K@rz`I+QnjeF?p$w-2nqIe$P1|^.J+/W7|Dr:v$4YM$');
define('NONCE_KEY',        'Frs5,2H`G~n]-6jz6cVM-B#vb0wK4<kIeH~cGH(*,IcN  Wr)F/4[fXz8XvfJ9-b');
define('AUTH_SALT',        '?JffVD?)TfRa?Z)E~#`2-?Pe=r6FJ|R8Rn4JD)lJa)-~=z9]^N$d|s+T4|7=lS;%');
define('SECURE_AUTH_SALT', '4sQJj1Q_Ca*opB>l1Bs~7~:t,-uFx+0cG _A(4eSZo~<POF|5|]y4`a@=pR.Ws-9');
define('LOGGED_IN_SALT',   'CY5%cY(V+]-CI(IHu.PCnFbT+<``z(a>qI$}K<K}Ezv=u@^>u`uRdT7fBeSft-Nt');
define('NONCE_SALT',       '=IBnuTbkqtcI#Z{]rfc?GEMxe.Y,R9%|8@MxA.|Yx?8TN9 yx}Vb^z=5~g4GXLOw');

// ########## REDIS CONFIGURATION ##########

define('WP_CACHE', true);
define('WP_REDIS_HOST', 'redis');
define('WP_REDIS_PORT', 6379);
// change the database for each site to avoid cache collisions
define( 'WP_REDIS_DATABASE', 0 );
// define( 'WP_REDIS_PASSWORD', 'CVKg0i5l4KgLEuL/L6IaXPlUHTs7rtfh6UVjnY4evkhwDEgz9al8teiifYtkBMIp8jk+X4AtYSqJdl00' );
define('WP_CACHE_KEY_SALT', 'wp_redis_');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', true );
define( 'WP_DEBUG_LOG', true );

/* That's all, stop editing! Happy publishing. */
/** Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
