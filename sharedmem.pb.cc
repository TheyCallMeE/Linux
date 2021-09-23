// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sharedmem.proto

#include "sharedmem.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace shmmsg {
constexpr Client::Client(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : msg_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , client_(1)
{}
struct ClientDefaultTypeInternal {
  constexpr ClientDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ClientDefaultTypeInternal() {}
  union {
    Client _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ClientDefaultTypeInternal _Client_default_instance_;
constexpr Server::Server(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : response_(1)
{}
struct ServerDefaultTypeInternal {
  constexpr ServerDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ServerDefaultTypeInternal() {}
  union {
    Server _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ServerDefaultTypeInternal _Server_default_instance_;
}  // namespace shmmsg
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_sharedmem_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_sharedmem_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_sharedmem_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_sharedmem_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::shmmsg::Client, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::shmmsg::Client, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::shmmsg::Client, client_),
  PROTOBUF_FIELD_OFFSET(::shmmsg::Client, msg_),
  1,
  0,
  PROTOBUF_FIELD_OFFSET(::shmmsg::Server, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::shmmsg::Server, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::shmmsg::Server, response_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::shmmsg::Client)},
  { 9, 15, sizeof(::shmmsg::Server)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::shmmsg::_Client_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::shmmsg::_Server_default_instance_),
};

const char descriptor_table_protodef_sharedmem_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017sharedmem.proto\022\006shmmsg\"n\n\006Client\0221\n\006c"
  "lient\030\001 \001(\0162\031.shmmsg.Client.ClientType:\006"
  "READER\022\013\n\003msg\030\002 \001(\t\"$\n\nClientType\022\n\n\006WRI"
  "TER\020\000\022\n\n\006READER\020\001\"^\n\006Server\0220\n\010response\030"
  "\001 \001(\0162\027.shmmsg.Server.Response:\005ERROR\"\"\n"
  "\010Response\022\013\n\007SUCCESS\020\000\022\t\n\005ERROR\020\001"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_sharedmem_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_sharedmem_2eproto = {
  false, false, 233, descriptor_table_protodef_sharedmem_2eproto, "sharedmem.proto", 
  &descriptor_table_sharedmem_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_sharedmem_2eproto::offsets,
  file_level_metadata_sharedmem_2eproto, file_level_enum_descriptors_sharedmem_2eproto, file_level_service_descriptors_sharedmem_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_sharedmem_2eproto_getter() {
  return &descriptor_table_sharedmem_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_sharedmem_2eproto(&descriptor_table_sharedmem_2eproto);
namespace shmmsg {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Client_ClientType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_sharedmem_2eproto);
  return file_level_enum_descriptors_sharedmem_2eproto[0];
}
bool Client_ClientType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr Client_ClientType Client::WRITER;
constexpr Client_ClientType Client::READER;
constexpr Client_ClientType Client::ClientType_MIN;
constexpr Client_ClientType Client::ClientType_MAX;
constexpr int Client::ClientType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Server_Response_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_sharedmem_2eproto);
  return file_level_enum_descriptors_sharedmem_2eproto[1];
}
bool Server_Response_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr Server_Response Server::SUCCESS;
constexpr Server_Response Server::ERROR;
constexpr Server_Response Server::Response_MIN;
constexpr Server_Response Server::Response_MAX;
constexpr int Server::Response_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

class Client::_Internal {
 public:
  using HasBits = decltype(std::declval<Client>()._has_bits_);
  static void set_has_client(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_msg(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

Client::Client(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:shmmsg.Client)
}
Client::Client(const Client& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_msg()) {
    msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_msg(), 
      GetArenaForAllocation());
  }
  client_ = from.client_;
  // @@protoc_insertion_point(copy_constructor:shmmsg.Client)
}

inline void Client::SharedCtor() {
msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
client_ = 1;
}

Client::~Client() {
  // @@protoc_insertion_point(destructor:shmmsg.Client)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Client::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Client::ArenaDtor(void* object) {
  Client* _this = reinterpret_cast< Client* >(object);
  (void)_this;
}
void Client::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Client::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Client::Clear() {
// @@protoc_insertion_point(message_clear_start:shmmsg.Client)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      msg_.ClearNonDefaultToEmpty();
    }
    client_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Client::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional .shmmsg.Client.ClientType client = 1 [default = READER];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::shmmsg::Client_ClientType_IsValid(val))) {
            _internal_set_client(static_cast<::shmmsg::Client_ClientType>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional string msg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "shmmsg.Client.msg");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Client::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:shmmsg.Client)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .shmmsg.Client.ClientType client = 1 [default = READER];
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_client(), target);
  }

  // optional string msg = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_msg().data(), static_cast<int>(this->_internal_msg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "shmmsg.Client.msg");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:shmmsg.Client)
  return target;
}

size_t Client::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:shmmsg.Client)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string msg = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_msg());
    }

    // optional .shmmsg.Client.ClientType client = 1 [default = READER];
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_client());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Client::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Client::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Client::GetClassData() const { return &_class_data_; }

void Client::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Client *>(to)->MergeFrom(
      static_cast<const Client &>(from));
}


void Client::MergeFrom(const Client& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:shmmsg.Client)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_msg(from._internal_msg());
    }
    if (cached_has_bits & 0x00000002u) {
      client_ = from.client_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Client::CopyFrom(const Client& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:shmmsg.Client)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Client::IsInitialized() const {
  return true;
}

void Client::InternalSwap(Client* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &msg_, GetArenaForAllocation(),
      &other->msg_, other->GetArenaForAllocation()
  );
  swap(client_, other->client_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Client::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_sharedmem_2eproto_getter, &descriptor_table_sharedmem_2eproto_once,
      file_level_metadata_sharedmem_2eproto[0]);
}

// ===================================================================

class Server::_Internal {
 public:
  using HasBits = decltype(std::declval<Server>()._has_bits_);
  static void set_has_response(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

Server::Server(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:shmmsg.Server)
}
Server::Server(const Server& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  response_ = from.response_;
  // @@protoc_insertion_point(copy_constructor:shmmsg.Server)
}

inline void Server::SharedCtor() {
response_ = 1;
}

Server::~Server() {
  // @@protoc_insertion_point(destructor:shmmsg.Server)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Server::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Server::ArenaDtor(void* object) {
  Server* _this = reinterpret_cast< Server* >(object);
  (void)_this;
}
void Server::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Server::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Server::Clear() {
// @@protoc_insertion_point(message_clear_start:shmmsg.Server)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  response_ = 1;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Server::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional .shmmsg.Server.Response response = 1 [default = ERROR];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::shmmsg::Server_Response_IsValid(val))) {
            _internal_set_response(static_cast<::shmmsg::Server_Response>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Server::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:shmmsg.Server)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .shmmsg.Server.Response response = 1 [default = ERROR];
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_response(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:shmmsg.Server)
  return target;
}

size_t Server::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:shmmsg.Server)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional .shmmsg.Server.Response response = 1 [default = ERROR];
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_response());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Server::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Server::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Server::GetClassData() const { return &_class_data_; }

void Server::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Server *>(to)->MergeFrom(
      static_cast<const Server &>(from));
}


void Server::MergeFrom(const Server& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:shmmsg.Server)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_response()) {
    _internal_set_response(from._internal_response());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Server::CopyFrom(const Server& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:shmmsg.Server)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Server::IsInitialized() const {
  return true;
}

void Server::InternalSwap(Server* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(response_, other->response_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Server::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_sharedmem_2eproto_getter, &descriptor_table_sharedmem_2eproto_once,
      file_level_metadata_sharedmem_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace shmmsg
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::shmmsg::Client* Arena::CreateMaybeMessage< ::shmmsg::Client >(Arena* arena) {
  return Arena::CreateMessageInternal< ::shmmsg::Client >(arena);
}
template<> PROTOBUF_NOINLINE ::shmmsg::Server* Arena::CreateMaybeMessage< ::shmmsg::Server >(Arena* arena) {
  return Arena::CreateMessageInternal< ::shmmsg::Server >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
