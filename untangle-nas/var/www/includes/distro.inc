<?php

/*
 *
 *
 * --------------------------------------------------------------------
 * Copyright (c) 2001 - 2008 Openfiler Project.
 * --------------------------------------------------------------------
 *
 * Openfiler is an Open Source SAN/NAS Appliance Software Distribution
 *
 * This file is part of Openfiler.
 *
 * Openfiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Openfiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Openfiler.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * This file was modified by Untangle, Inc. in 2009.
 * These changes are Copyright (c) 2009 Untangle, Inc.
 *
 * --------------------------------------------------------------------
 *
 *  
 */



function htmlEntitiesWrapper ($string) {

    return htmlentities($string, ENT_COMPAT, "UTF-8");
    
}

$lvm_version = 2;
// $lvm_version = 1;

// $lvm_command_prefix = "/usr/sbin/lvm ";
$lvm_command_prefix = "/sbin/lvm ";

$fs_info = array(
                array(
                    "type" => "ext3",
                    "name" => "Ext3",
                    "fs_block_size" => 1024,
                    "mkfs_command" => "/sbin/mke2fs -j",
                    "mount_options" => "defaults,usrquota,grpquota,acl,user_xattr",
                    "snapshot_mount_options" => "defaults,acl,user_xattr", 
                    "resize_command" => "/usr/bin/sudo /sbin/resize2fs"
                ),

                array(
                    "type" => "xfs",
                    "name" => "XFS",
                    "fs_block_size" => 1024,
                    "mkfs_command" => "/sbin/mkfs.xfs -f",
                    "mount_options" => "defaults,usrquota,grpquota",
                    "snapshot_mount_options" => "defaults,nouuid",
                    "resize_command" => "/usr/bin/sudo /usr/sbin/xfs_growfs"
                ),
    
    
                /*

                array(
                    "type" => "jfs",
                    "name" => "JFS",
                    "fs_block_size" => 1024,
                    "mkfs_command" => "/usr/sbin/mkfs.jfs -q",
                    "mount_options" => "defaults",
                    "snapshot_mount_options" => "defaults",
                    "resize_command" => " "
                
                ),
                                
                array(
                    "type" => "reiserfs",
                    "name" => "reiserfs",
                    "fs_block_size" => 1024,
                    "mkfs_command" => "/sbin/mkfs.reiserfs -q",
                    "mount_options" =>  "defaults,usrquota,grpquota,acl",
                    "snapshot_mount_options" => "defaults,acl",
                    "resize_command" => "/usr/bin/sudo /sbin/resize_reiserfs -f"
                ),*/
    
                array(
                    "type" => "iscsi",
                    "name" => "iSCSI",
                    "fs_block_size" => 0, 
                    "mkfs_command" => "/bin/true",
                    "mount_options" => "",
                    "snapshot_mount_options" => "",
                    "resize_command" => "/bin/true"
                ),


        );
?>