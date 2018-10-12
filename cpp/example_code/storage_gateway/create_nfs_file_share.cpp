 
//snippet-sourcedescription:[<<FILENAME>> demonstrates how to ...]
//snippet-keyword:[C++]
//snippet-keyword:[Code Sample]
//snippet-service:[AWS Storage Gateway]
//snippet-sourcetype:[full-example]
//snippet-sourcedate:[]
//snippet-sourceauthor:[tapasweni-pathak]


/*
   Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
   This file is licensed under the Apache License, Version 2.0 (the "License").
   You may not use this file except in compliance with the License. A copy of
   the License is located at
    http://aws.amazon.com/apache2.0/
   This file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied. See the License for the
   specific language governing permissions and limitations under the License.
*/

#include <aws/core/Aws.h>
#include <aws/storagegateway/StorageGatewayClient.h>
#include <aws/storagegateway/model/CreateNFSFileShareRequest.h>
#include <aws/storagegateway/model/CreateNFSFileShareResult.h>
#include <iostream>

int main(int argc, char ** argv)
{
  if (argc != 5)
  {
    std::cout << "Usage: create_nfs_file_share <gateway_arn> <client_token> <location_arn> <role>" << std::endl;
    return 1;
  }

  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    Aws::String gateway_arn(argv[1]);
    Aws::String client_token(argv[2]);
    Aws::String location_arn(argv[3]);
    Aws::String role(argv[4]);

    Aws::StorageGateway::StorageGatewayClient storagegateway;

    Aws::StorageGateway::Model::CreateNFSFileShareRequest cnfsfs_req;

    cnfsfs.SetGatewayARN(gateway_arn);
    cnfsfs.SetRole(role);
    cnfsfs.SetLocationARN(location_arn);
    cnfsfs.AddClientList(client_token);

    auto cnfsfs_out = storagegateway.CreateNFSFileShare(cnfsfs_req);

    if (cnfsfs_out.IsSuccess())
    {
      std::cout << "Successfully created NFS File share" << std::endl;
    }
    else
    {
      std::cout << "Error creating NFS File share" << cnfsfs_out.GetError().GetMessage()
        << std::endl;
    }
  }

  Aws::ShutdownAPI(options);
  return 0;
}
