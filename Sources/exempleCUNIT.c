//
// fichier max_test2-td
//
//  Created by Claudine Piau-Toffolon on 21/10/2014.
//  Copyright (c) 2014 Claudine Piau-Toffolon. All rights reserved.
//


#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
//#include "CUnit/Automated.h"
//#include "CUnit/Console.h"

#include <stdio.h>  // for printf


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }



int max(int i1, int i2)
    {
      return (i1 > i2) ? i1 : i2;
    }
    
    
void test_case_sample(void)
{
    CU_ASSERT(CU_TRUE);
    CU_ASSERT_NOT_EQUAL(2, -1);
    CU_ASSERT_STRING_EQUAL("string #1", "string #1");
    CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");
    
    CU_ASSERT(CU_FALSE);
    CU_ASSERT_EQUAL(2, 3);
    CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
    CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}

void max_test_1(void) {
    CU_ASSERT_EQUAL( max(1,2), 2);
    CU_ASSERT_EQUAL( max(2,1), 2);
}

void max_test_2(void) {
    CU_ASSERT_EQUAL( max(2,2), 2);
    CU_ASSERT_EQUAL( max(0,0), 0);
    CU_ASSERT_EQUAL( max(-1,-1), -1);
}

void max_test_3(void) {
    CU_ASSERT_EQUAL( max(-1,-2), -1);
}


int main ( void )
{
    CU_pSuite pSuite = NULL;
    
       if ( CUE_SUCCESS != CU_initialize_registry() )
        return CU_get_error();

    pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite );
    if ( NULL == pSuite ) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    

    if ( (NULL == CU_add_test(pSuite, "max_test_1", max_test_1)) ||
        (NULL == CU_add_test(pSuite, "max_test_2", max_test_2)) ||
        (NULL == CU_add_test(pSuite, "max_test_3", max_test_3))
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    CU_cleanup_registry();
    return CU_get_error();
}
