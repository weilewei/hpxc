//  Copyright (c) 2007-2012 Hartmut Kaiser
//  Copyright (c) 2011-2012 Bryce Adelstein-Lelbach
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPXC_THREADS_THREAD_18_SEP_2012_0134PM)
#define HPXC_THREADS_THREAD_18_SEP_2012_0134PM

#include <hpxc/config/export_definitions.hpp>

extern "C"
{
    ///////////////////////////////////////////////////////////////////////////
    struct hpxc_thread_t { void* handle; };
    struct hpxc_thread_attr_t { void* handle; };

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Creates a new thread of execution.
    HPXC_API_EXPORT int hpxc_thread_create(
        hpxc_thread_t* thread_id, 
        hpxc_thread_attr_t const* attributes,
        void* (*thread_function)(void*), 
        void* arguments);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Suspend the calling thread until the target thread terminates.
    // FIXME: value_ptr not implemented.
    HPXC_API_EXPORT int hpxc_thread_join(
        hpxc_thread_t* thread_id,
        void** value_ptr);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Terminates the calling thread.
    // FIXME: value_ptr not implemented.
    HPXC_API_EXPORT void hpxc_thread_exit(void* value_ptr);
}

#endif
