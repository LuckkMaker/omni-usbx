/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation 
 * 
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 * 
 * SPDX-License-Identifier: MIT
 **************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */ 
/** USBX Component                                                        */ 
/**                                                                       */
/**   Pictbridge Application                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/* Include necessary system files.  */

#define UX_SOURCE_CODE

#include "ux_api.h"
#include "ux_pictbridge.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _ux_pictbridge_xml_function_input_notifydevicestatus_errorstatus    */ 
/*                                                        PORTABLE C      */ 
/*                                                           6.1          */
/*                                                                        */ 
/*                                                                        */ 
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*    This function decodes the errorstatus tag                           */ 
/*    object                                                              */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    pictbridge                             Pictbridge instance          */ 
/*    input_variable                         Pointer to variable          */ 
/*    input_string                           Pointer to string            */ 
/*    xml_parameter                          XML parameter                */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    Completion Status                                                   */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*                                                                        */ 
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    _ux_pictbridge_object_parse                                         */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */ 
/*                                                                        */ 
/*  05-19-2020     Chaoqiong Xiao           Initial Version 6.0           */
/*  09-30-2020     Chaoqiong Xiao           Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*                                                                        */
/**************************************************************************/
UINT  _ux_pictbridge_xml_function_input_notifydevicestatus_errorstatus(UX_PICTBRIDGE *pictbridge, 
                            UCHAR *input_variable, UCHAR *input_string, UCHAR *xml_parameter)
{

UINT    status;
ULONG   hexa_element;

    UX_PARAMETER_NOT_USED(input_string);
    UX_PARAMETER_NOT_USED(input_variable);
    UX_PARAMETER_NOT_USED(xml_parameter);

    /* Get the error status variable.  */
    status = _ux_pictbridge_element_to_hexa(xml_parameter, &hexa_element);

    /* Check status.  */
    if (status == UX_SUCCESS)
    {

        /* Check the returned value. Must be one of 3 possibilities.  */
        if (hexa_element == UX_PICTBRIDGE_ERROR_STATUS_NO_ERROR ||
            hexa_element == UX_PICTBRIDGE_ERROR_STATUS_WARNING  ||
            hexa_element == UX_PICTBRIDGE_ERROR_STATUS_FATAL)
        {

            /* Save this value.  */
            pictbridge -> ux_pictbridge_dpsclient.ux_pictbridge_devinfo_errorstatus = hexa_element;

            /* We are done. */
            return(UX_SUCCESS);
        }
    }

    /* We get here when we reached an unexpected end of the XML object or a format error.  */
    return(UX_PICTBRIDGE_ERROR_SCRIPT_SYNTAX_ERROR);

}


