/*******************************************************************************
* Copyright 2021 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef SYCL_SYCL_COMPAT_HPP
#define SYCL_SYCL_COMPAT_HPP

#include "gpu/compute/compute.hpp"
#include "sycl/sycl_utils.hpp"

namespace dnnl {
namespace impl {
namespace sycl {

class sycl_gpu_engine_t;

namespace compat {

status_t make_kernel(std::unique_ptr<::sycl::kernel> &sycl_kernel,
        const std::string &kernel_name, const sycl_gpu_engine_t *sycl_engine,
        void *native_program_handle, const gpu::compute::binary_t *binary,
        gpu::compute::program_list_t *programs);

status_t make_kernel(std::unique_ptr<::sycl::kernel> &sycl_kernel,
        const std::string &kernel_name, const sycl_gpu_engine_t *sycl_engine,
        const gpu::compute::binary_t *binary,
        const gpu::compute::program_list_t *programs);

std::function<void(void *)> get_program_list_deleter();

} // namespace compat
} // namespace sycl
} // namespace impl
} // namespace dnnl

#endif