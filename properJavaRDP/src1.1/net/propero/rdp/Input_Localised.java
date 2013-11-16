/* Input_Localised.java
 * Component: ProperJavaRDP
 * 
 * Revision: $Revision: 1.7 $
 * Author: $Author: telliott $
 * Date: $Date: 2005/09/27 14:15:38 $
 *
 * Copyright (c) 2005 Propero Limited
 *
 * Purpose: Java 1.1 specific extension of Input class
 */
// Created on 03-Sep-2003

package net.propero.rdp;

import net.propero.rdp.keymapping.KeyCode;
import net.propero.rdp.keymapping.KeyCode_FileBased;

public class Input_Localised extends Input {

	public Input_Localised(RdesktopCanvas c, Rdp r, String k){
		super(c,r,k);
	}
	
	public Input_Localised(RdesktopCanvas c, Rdp r, KeyCode_FileBased k){
		super(c,r,k);
	}
}