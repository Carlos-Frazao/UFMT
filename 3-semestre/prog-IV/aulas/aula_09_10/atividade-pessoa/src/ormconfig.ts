export const config = {
  type: 'sqlite' as const,
  database: '.db/sql',
  synchronize: true,
  autoLoadEntities: true,
};