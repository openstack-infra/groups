<?php


/**
 * Map group location into an array processed by json export.
 * @param  object $entity Group entity
 * @return object         group class representation.
 *
 * @see groups_feeds_json_export_groups()
 */
function groups_feeds_json_map_location($entity) {
  $location = new stdClass();
  $location->country = $entity->field_group_location[LANGUAGE_NONE][0]['country'];
  $location->continent = $entity->field_group_location[LANGUAGE_NONE][0]['continent'];
  if (isset($entity->field_group_location[LANGUAGE_NONE][0]['location'])) {
    $location->location = $entity->field_group_location[LANGUAGE_NONE][0]['location'];
  }
  $location->lat = $entity->field_geofield[LANGUAGE_NONE][0]['lat'];
  $location->lon = $entity->field_geofield[LANGUAGE_NONE][0]['lon'];
  return $location;
}

/**
 * Map group attributes into an array processed by json export.
 * @param  object $entity Group entity
 * @return object         group class representation.
 *
 * @see groups_feeds_json_export_groups()
 */
function groups_feeds_json_map_attributes($entity) {
  static $attr_list_lookup;
  if ($attr_list_lookup == NULL) {
    $attr_list_lookup = array_flip(field_property_list_reverse_lookup());
  }
  $attributes = array();
  foreach ($entity->field_resource_links[LANGUAGE_NONE] as $resource) {
    $attr = new stdClass();
    $key = $attr_list_lookup[$resource['key']];
    if (isset($key)) {
      $attr->$key = $resource['value'];
      $attributes[] = $attr;
    }
  }
  return $attributes;
}

/**
 * Map a group entity into an array processed by json export.
 * @param  object $entity Group entity
 * @return object         group class representation.
 *
 * @see groups_feeds_json_export_groups()
 */
function groups_feeds_json_map_group($entity) {
  $group = new stdClass();
  $group->title = $entity->title;
  $result = db_query('SELECT fi.guid FROM {feeds_item} fi WHERE fi.entity_id = :entity_id', array(':entity_id' =>$entity->nid));
  $row = $result->fetchObject();
  if (isset($row->guid)) {
    $group->id = $row->guid;
  }
  $group->location = groups_feeds_json_map_location($entity);
  if (isset($entity->field_resource_links[LANGUAGE_NONE])) {
    $group->attributes = groups_feeds_json_map_attributes($entity);
  }
  return $group;
}

/**
 * Export groups data in json format.
 *
 * @return json output of groups.
 */
function groups_feeds_json_export_groups() {
  $container = new stdClass();
  $container->groups = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'group');
  $result = $query->execute();
  $nids = array_keys($result['node']);
  $nid = reset($nids);
  foreach ($nids as $nid) {
    $entity = node_load($nid);
    $container->groups[] = groups_feeds_json_map_group($entity);
  }
  drupal_add_http_header('Content-Type', 'application/json');
  // @see php bug #49366 Make slash escaping optional in json_encode()
  $json = str_replace('\\/', '/', json_encode($container));
  echo $json;
}