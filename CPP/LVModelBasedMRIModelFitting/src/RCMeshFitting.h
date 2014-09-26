/*******************************************************************************
 *  Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 *  The contents of this file are subject to the Mozilla Public License
 *  Version 1.1 (the "License"); you may not use this file except in
 *  compliance with the License. You may obtain a copy of the License at
 *  http://www.mozilla.org/MPL/
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *  License for the specific language governing rights and limitations
 *  under the License.
 *
 *  The Original Code is ICMA
 *
 *  The Initial Developer of the Original Code is University of Auckland,
 *  Auckland, New Zealand.
 *  Copyright (C) 2007-2010 by the University of Auckland.
 *  All Rights Reserved.
 *
 *  Contributor(s): Jagir R. Hussan
 *
 *  Alternatively, the contents of this file may be used under the terms of
 *  either the GNU General Public License Version 2 or later (the "GPL"), or
 *  the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 *  in which case the provisions of the GPL or the LGPL are applicable instead
 *  of those above. If you wish to allow use of your version of this file only
 *  under the terms of either the GPL or the LGPL, and not to allow others to
 *  use your version of this file under the terms of the MPL, indicate your
 *  decision by deleting the provisions above and replace them with the notice
 *  and other provisions required by the GPL or the LGPL. If you do not delete
 *  the provisions above, a recipient may use your version of this file under
 *  the terms of any one of the MPL, the GPL or the LGPL.
 *
 * "2014"
 *******************************************************************************/
/***
 *      This class does not invoke any optimization procedures, rather it sets the input coordinate/xi pair
 *      on the target mesh (which is what surface fit would produce)
 *
 */

#ifndef RCMESHFITTING_H_
#define RCMESHFITTING_H_

extern "C" {
#include "zn/cmiss_context.h"
#include "zn/cmiss_stream.h"
#include "zn/cmiss_field.h"
#include "zn/cmiss_field_arithmetic_operators.h"
#include "zn/cmiss_field_composite.h"
#include "zn/cmiss_field_constant.h"
#include "zn/cmiss_field_finite_element.h"
#include "zn/cmiss_field_group.h"
#include "zn/cmiss_field_module.h"
#include "zn/cmiss_field_matrix_operators.h"
#include "zn/cmiss_field_nodeset_operators.h"
#include "zn/cmiss_field_subobject_group.h"
#include "zn/cmiss_field_trigonometry.h"
#include "zn/cmiss_field_vector_operators.h"
#include "zn/cmiss_element.h"
#include "zn/cmiss_graphic.h"
#include "zn/cmiss_graphics_module.h"
#include "zn/cmiss_node.h"
#include "zn/cmiss_optimisation.h"
#include "zn/cmiss_region.h"
#include "zn/cmiss_rendition.h"
#include "zn/cmiss_status.h"
#include "zn/cmiss_tessellation.h"
}

#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "Point3D.h"

class RCMeshFitting {
private:
	int myID;
	static int id;
protected:
	std::vector<Cmiss_node_id> meshNodeID;
	Cmiss_field_cache_id cache;
	Cmiss_context_id context_;
	Cmiss_field_module_id field_module_;
	Cmiss_field_id coordinates_rc_;

public:
	RCMeshFitting();
	virtual ~RCMeshFitting();
	std::string getOptimizedMesh(std::vector<Point3D>& markers,std::vector<Point3D>* emarkers=NULL);
};

/***
 * Note that rotation and scaling of markers introduces small changes in the
 * apex value (when epi apex is used for aligning model), in such cases the first
 * encouter of the endo apex value is chosen and this will impact the strain measurements
 */

#endif /* RCMESHFITTING_H_ */
