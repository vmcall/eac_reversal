unsigned __int64 __fastcall cerberus::entry(cerberus_extended_context *context, __int64 a2, void (__fastcall *log_fn)(_QWORD, const char *, __int64), __int64 a4)
{
  cerberus_thread_context *io_thread_context; // r14
  char *encrypted_local_buffer_1; // rdi
  char *encrypted_buffer; // rsi
  signed __int64 i; // rcx
  __int64 index; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // r8
  char *str_P2P; // [rsp+Fh] [rbp-69h]
  char initialize_message[13]; // [rsp+1Bh] [rbp-5Dh]
  char encrypted_local_buffer[32]; // [rsp+28h] [rbp-50h]
  unsigned __int64 stack_guard; // [rsp+48h] [rbp-30h]

  io_thread_context = &context->thread_context_1;
  stack_guard = __readfsqword(0x28u);
  create_cerberus_thread_0(&context->thread_context_1);
  encrypted_local_buffer_1 = encrypted_local_buffer;
  encrypted_buffer = encrypted_Initialize;
  for ( i = 8LL; i; --i )
  {
    *(_DWORD *)encrypted_local_buffer_1 = *(_DWORD *)encrypted_buffer;
    encrypted_buffer += 4;
    encrypted_local_buffer_1 += 4;
  }
  index = 0LL;
  do
  {
    initialize_message[index] = encrypted_local_buffer[index] ^ 0x4C;
    ++index;
  }
  while ( index != 13 );
  cerberus_sprintf(io_thread_context, 3u, initialize_message, encrypted_local_buffer);// [Initialize]
  unknown_log(initialize_message, 13LL);
  cerberus::create_https_client(context);
  cerberus::setup_thread_Context(&context->thread_context_3);
  cerberus::start_thread(&context->thread_context_3);
  cerberus_encryption::ctor(&context->encryption_struct);
  basic_string::ctor((char **)((char *)&str_P2P + 1), "P2P", (__int64)&str_P2P);
  cerberus::initialise(&context->init_context, (char **)((char *)&str_P2P + 1), v12, v13, v14);
  basic_string::dtor((char **)((char *)&str_P2P + 1));
  log_fn(0LL, "EasyAntiCheat successfully initialized", a4);
  return __readfsqword(0x28u) ^ stack_guard;
}

