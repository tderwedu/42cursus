<?php

// ########## REDIS CONFIGURATION ##########

define('WP_REDIS_HOST', 'redis');
define('WP_REDIS_PORT', 6379);
// change the database for each site to avoid cache collisions
define( 'WP_REDIS_DATABASE', 0 );

?>
