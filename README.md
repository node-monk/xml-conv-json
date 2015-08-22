# xml-conv-json
Node Module that converts XML to JSON using a C++ Module

This module has the advantage of using C++ to crunch the XML and return it as JSON instead of using Node for such an intensive operation.

It is simply a wrapper for the  https://github.com/Cheedoong/xml2json C++ library


## Install

node gyp will need to be installed globally. You can install it with
```

  npm install -g node-gyp

```

Install xml-conv-json package
```

  npm install --save xml-conv-json

```

## Use

```javascript

  var xmlConvJson=require('xml-conv-json');
  
  var jsonObj=xmlConvJson.parseXML(xmlString);
  
```


## To Do
Create an Asyncronous version using libuv ( Pull Request Welcome :) )
