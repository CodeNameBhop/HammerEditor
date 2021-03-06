//***************************************************************************************
//
// File supervisor: Softimage 3D Games & 3D Bridge team
//
// (c) Copyright 2001-2005 Avid Technology, Inc. . All rights reserved.
//
//***************************************************************************************

/****************************************************************************************
THIS CODE IS PUBLISHED AS A SAMPLE ONLY AND IS PROVIDED "AS IS".
IN NO EVENT SHALL SOFTIMAGE, AVID TECHNOLOGY, INC. AND/OR THEIR RESPECTIVE
SUPPLIERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS CODE .

COPYRIGHT NOTICE. Copyright ? 1999-2002 Avid Technology Inc. . All rights reserved. 

SOFTIMAGE is a registered trademark of Avid Technology Inc. or its subsidiaries 
or divisions. Windows NT is a registered trademark of Microsoft Corp. All other
trademarks contained herein are the property of their respective owners. 
****************************************************************************************/

#ifndef _XSITRIANGLELIST_H
#define _XSITRIANGLELIST_H

#include "XSISubComponentList.h"
#include "Material.h"


//!Describes a list of triangles for dotXSI 5.0+
/**
* The CSLXSITriangleList class describes a list of triangles
* The polynodes in this list can have N number of attibutes like vertex, normals, UV and color information. 
*
* To find out, you may use GetVertexIndices() to get the mendatory vertex index attributes and
* the parent class (CSLXSISubComponentList) functionality to get the other generic attributes index.
*
* To get the number of triangles in the list, use GetTriangleCount(). 
* 
*/
class XSIEXPORT CSLXSITriangleList
	: public CSLXSISubComponentList
{
public:
	/*! Constructor	
	* \param in_pScene Parent scene
	* \param in_pModel Parent model
	* \param in_pTemplate Refered template
	* \return an instance of CSLXSITriangleList
	*/
	CSLXSITriangleList(CSLScene *in_pScene, CSLModel *in_pModel, CdotXSITemplate *in_pTemplate);

	/*! Destructor
	*/
	virtual ~CSLXSITriangleList();

	/*! Returns the type of this template (XSI_TRIANGLE_LIST)
		\return CSLTemplate::ETemplateType The type of this template (XSI_TRIANGLE_LIST)
	*/
	virtual ETemplateType			Type() { return XSI_TRIANGLE_LIST; }

	/*!	Return the material object of the triangle list.
		\return	CSLBaseMaterial*	Material object.
	*/
	CSLBaseMaterial*				GetMaterial() { return m_pMaterial; }

	/*!	Change the material object of the triangle list.
		\param	CSLBaseMaterial*	New material object.
		\return	None
	*/
	SI_Void							SetMaterial(CSLBaseMaterial *in_pNewMaterial) { m_pMaterial = in_pNewMaterial; }

	/*! Get the polynode vertex indices array.
	* \return	CSLIntArray	Array of polynode vertex indices.
	*/
	CSLIntArray*					GetVertexIndices();

	/*! Get the number of triangle.
	* \return	SI_Int	Number of triangle.
	*/
	SI_Int							GetTriangleCount();

	/*! Set the number of polynode in this triangle list.
	* \return	SI_Error	Error code.
	*/
	virtual SI_Error				SetCount(SI_Int);

	/*! Commit the current template information
		\return SI_Error Whether or not the commit was successful
	*/
	SI_Error Synchronize();

private:
	CSLIntArray						m_VertexIndices;

	CSLBaseMaterial*				m_pMaterial;

	void *m_pReserved;	// reserved for future extension
};

#endif
