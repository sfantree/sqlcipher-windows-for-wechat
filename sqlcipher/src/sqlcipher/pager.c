/* BEGIN CRYPTO */
#ifdef SQLITE_HAS_CODEC
void sqlite3pager_get_codec(Pager *pPager, void **ctx) {
  *ctx = pPager->pCodec;
}

int sqlite3pager_is_mj_pgno(Pager *pPager, Pgno pgno) {
  return (PAGER_MJ_PGNO(pPager) == pgno) ? 1 : 0;
}

sqlite3_file *sqlite3Pager_get_fd(Pager *pPager) {
  return (isOpen(pPager->fd)) ? pPager->fd : NULL;
}

void sqlite3pager_sqlite3PagerSetCodec(
  Pager *pPager,
  void *(*xCodec)(void*,void*,Pgno,int),
  void (*xCodecSizeChng)(void*,int,int),
  void (*xCodecFree)(void*),
  void *pCodec
){
  sqlite3PagerSetCodec(pPager, xCodec, xCodecSizeChng, xCodecFree, pCodec); 
}

void sqlite3pager_sqlite3PagerSetError( Pager *pPager, int error) {
  pPager->errCode = error;
}

#endif
/* END CRYPTO */

